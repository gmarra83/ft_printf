# ft_printf - Bonus Track

## ft_printf.c

```c
int ft_printf(const char *str, ...)    #prototipo della funzione
```

Possiamo pensare di analizzare la stringa carattere per carattere. Se viene trovato il segnaposto '%'' allora si procede all’analisi del segnaposto e si fa la conversione dell’argomento passato come parametro variabile.

```flowchart
st=>start: Start
op=>operation: String Iteration
op2=>operation: run_format_eval Fnc
op3=>operation: Print
cond=>condition: Found '%'?
e=>end: Fine

st->op->cond
cond(no)->op3
cond(yes)->op2->op3
```

L'idea è quella di realizzare una struttura che ci potrà essere di aiuto. La struttura dovrà avere 4 campi. Nel dettaglio sarà così composta:

```c
typedef struct s_placeholder
{
    unsigned int    flgmask;
    int                width;
    int                precision;
    int                format_type;
    char            *str;
}    t_placeholder;
```

In pratica dall'analisi del formato otterrò:

- `flgmask` la configurazione dei flag rappresentati con una bitmask 

- `width` la minima "larghezza" dell'output 

- `precision` la "precision"

- `format_type` il tipo di segnaposto individuato

- `*str` la stringa convertita MA non formattata 

Per settare, resettare e valutare i bit presenti nella bitmask sono state implementate 3 funzioni inline:

```c
static inline void    set_bit(unsigned int *mask, unsigned int bit_pos)
{
    *mask |= 1U << bit_pos;
}

static inline void    reset_bit(unsigned int *mask, unsigned int bit_pos)
{
    *mask &= ~(1U << bit_pos);
}

static inline unsigned int    get_bit(unsigned int mask, unsigned int bit_pos)
{
    return ((mask >> bit_pos) & 1U);
}
```

Per andare a manipolare la bitmask in maniera più comoda si è utilizzata una enum:

```c
enum e_bitmask
{
    MINUS = 0,    #flag '-', allineamento a sx
    PLUS = 1,     #flag '+', esplicita il segno '+' con i num positivi   
    SPACE = 2,    #flag ' ', mette uno ' ' ai numeri positivi
    ZERO = 3,     #flag '0', mette '0' sulle cifre mancanti secondo width
    HASHTAG = 4,  #flag '#', mette 
    WIDTH = 5,
    DOT = 6,
    IS_ZERO = 7,
    IS_NEG = 8
};
```

---

```c
void    run_format_eval(va_list args, const char **format, int *char_printed)
```

Questa funzione prende in input: la lista degli argomenti variabili (`va_list args`), il puntatore carattere per riferimento (`const char **format`) e il contatore dei caratteri stampati (`int *char_printed`). Deve quindi analizzare carattere per carattere cosa c’è dopo `%`, popolare una maschera bit con i flag attivi, calcolare i valori di width e precision e chiamare la funzione corretta per la conversione dell’argomento passandogli il tipo da convertire, i flag e l’argomento preso dalla lista. Le funzioni di conversione devono ritornare una stringa con la conversione effettuata che sarà memorizzata nella struttura. Una volta effettuata la conversione in stringa questa verrà poi valutata insieme ad i flags per ottenere la formattazione finale. A seconda del tipo di formato identificato verrà applicata la corretta conversione.

**NB**: mi raccomando di mettere `arg list` sempre come PRIMO argomento, altrimenti si possono avere dei warning di accessi alla memoria oltre i limiti!

La funzione in oggetto chiama diverse funzioni di helper. Nello specifico il flusso logico è il seguente:

1. `void flag_eval(const char **format, t_placeholder *data)`: controlla se il carattere selezionato `**format` nella stringa di formattazione fa parte del set di caratteri di `"-+ 0#"`. In caso imposta il bit corrispondente nella maschera bit (`data->flgmask`) e sposta il puntatore del carattere di `*format`

2. `void width_prec_eval(const char **format, t_placeholder *data, va_list args)`: valuta se è presente il campo **width** o la **precision**. Gli passo quindi la struttura (`t_placeholder *data`), la stringa di formattazione per riferimento (`const char **format`) e anche la lista degli argomenti (`va_list args`) in caso fosse presente il carattere `*`. In pratica il codice è fatto per riconoscere se c'è un carattere facente parte di un set predefinito (`"0123456789.*"`) nella stringa di formattazione e, in caso, lo converte in numero ed imposta **width**, **precision** ed i rispettivi flags (`WIDTH`e `DOT`).
   
   NB: la width viene sempre prima della precision.

3. `void eval_flg_prio(unsigned int *flgmask, int *width, int *precision)`: questa funzione va a cambiare i flag della bitmask a seconda delle priorità dei modificatori secondo la tabella seguente:

| Flag | Mask      | Descrizione                                | Priorità | Conflitti con... | Comportamento in caso di conflitto                                   |
| ---- | --------- | ------------------------------------------ | -------- | ---------------- | -------------------------------------------------------------------- |
| `-`  | `MINUS`   | Allinea a sinistra                         | Alta     | `0`              | Se `-` è presente, `0` viene ignorato.                               |
| `0`  | `ZERO`    | Padding con zeri                           | Media    | `-`, `.`         | Se `-` o `.` sono presenti, `0` viene ignorato.                      |
| `+`  | `PLUS`    | Sempre segno per numeri                    | Alta     | ` `              | `+` ha priorità su ` `.                                              |
| ` `  | `SPACE`   | Aggiunge spazio prima di numeri positivi   | Bassa    | `+`              | Se `+` è presente,` ` viene ignorato.                                |
| `#`  | `HASHTAG` | Prefisso `0x`, `0X`, `0` per `x`, `X`, `o` | Media    | Nessuno          | Si applica solo a `x`, `X`, `o`, e viene ignorato per altri formati. |
| `.`  | `DOT`     | Min. cifre per numeri, taglio stringhe     | Alta     | `0`              | Se c'è una precisione per numeri interi, `0` viene ignorato.         |
| `*`  |           | Larghezza o precisione da va_arg           | Dipende  | Nessuno          | Sostituisce direttamente larghezza o precisione.                     |

4. `void    format_str(t_placeholder *data2process)` viene chiamata la funzione in oggetto che modifica la stringa presente nella struttura secondo i flags. Tale funzione utilizza una serie di helper.
5. `void    write_char_str(const char *str, int *cnt, unsigned int str_flg,      unsigned int flgmask)`: questa è la funzionalità che si occupa nello specifico di andare a scrivere sullo `stdout` con il comando `write` la stringa passatagli. A seconda della tipologia di dato effettua alcuni controlli. Fondamentalmente gestisce i casi speciali dove passiamo un tipo `'char'` con valore `'\0'` (sia singolo che con le opzioni di `width` e/o `minus`.

---

## ft_printf_utils_parsing.c

In questo file sono presenti le funzioni che si occuperanno di fare il parsing dei flags con la stringa convertita andandola a modificare. La funzione principale è:

```c
void    format_str(t_placeholder *data2process)
```

la quale gestisce i valori NULL sia di stringhe che di puntatori e chiama altre funzioni di helper nel seguente ordine:

1. `void calc_bitmask(unsigned int *flgmask, int format_type)`: funzione che, a partire dai flags e dal tipo di segnaposto va ad escludere i bit non compatibili secondo la seguente tabella:
   
   ![](asset_ft_printf%20-%20Bonus%20Track/2025-02-03-15-38-32-image.png)
   
   Per questo motivo nel file .h andiamo a definire un enum con i seguenti valori
   
   ```c
   enum e_typemask
   {
       CHR = 0xA1,
       STR = 0x61,
       PTR = 0x61,
       DEC = 0x16F,
       INT = 0x16F,
       UINT = 0x6D,
       HEX = 0x79
   };
   ```

2. `void evaluate_flags(t_placeholder *data)`: funzione che va ad applicare la formattazione sulla base della bitmask (`data->flgmask`). In pratica vado a valutare quale flag è attivo e, a seconda dello stato, modifico la stringa presente nella struttura (`data->str`). La funzione utilizza degli helper, nello specifico:
   
   - `void format_precision(t_placeholder *data)`: a seconda del campo precision e del `data->format_type` vado a modificare la stringa andando ad aggiungere `0` oppure a tagliare in caso di stringa.
   
   - `void format_width(t_placeholder *data)`: a seconda del campo width va ad inserire ` ` in base a quanti caratteri sono mancanti, oppure `0` in caso di presenza del flag `ZERO`. In caso di aggiunta ` ` questi verranno posti prima o dopo della stringa convertita in base allo stato del flag `MINUS`. Per ultimo fa anche una verifica, chiamando `check_sign_zero(data)`, per assicurarsi che un eventuale segno (`+` o `-`) sia messo sempre prima del primo carattere numerico.
     
     NB: se presente flag `MINUS`e flag `ZERO`quest'ultimo viene ignorato.

---

## Funzioni ausiliarie

Le funzioni ausiliarie sono contenute nei files:

- **ft_printf_utils.c** --> Racchiude al suo interno diverse funzionalità di utilizzo generale. In particolar modo:
  
  ```c
  //ft_memmove: sposta n bytes da src a dst
  static void    *ft_memmove(void *dest, const void *src, size_t n)
  
  //ftpf_memset: a partire da *s setta n byte = c
  void    ftpf_memset(void *s, int c, size_t n)
  
  //ft_strshrink: ridimensiona str facendola diventare di grandezza new_dim
  char    *ft_strshrink(char *str, size_t curr_dim, size_t new_dim)
  
  //check_sign_zero: controlla che, in presenza del flag 0, eventuali segni
  //    siano posti prima della prima cifra e non nel mezzo della stringa. 
  void    check_sign_zero(t_placeholder *data)
  
  //write_char_str: si occupa di scrivere nello stdout la stringa str
  void    write_char_str(const char *str, int *cnt, unsigned int str_flg,
              unsigned int flgmask)
  ```

- **ft_printf_utils_conv.c** --> al suo interno sono presenti le funzioni per poter fare la conversione degli argomenti. nello specifico:
  
  ```c
  //convert_arg: si occupa di indirizzare la chiamata alla conversione da
  //    fare in base al format_type
  char    *convert_arg(int format_type, va_list args, unsigned int *flgmask)
  
  //ftpf_itoa: converte qualsiasi numero in una stringa. I numeri sono presi
  //    come unsigned, un eventuale segno viene memorizzato nel flag IS_NEG e
  //    valutato in fase di processamento dei flags.
  static char    *ftpf_itoa(t_convtypenum n, unsigned int base,
          unsigned int *flgmask, int format_type)
  
  //conv_chr: crea una stringa composta da un solo carattere char
  static char    *conv_chr(char charnum)
  ```

```
NB: da notare che la gestione dei numeri (%p, %d, %i, %u, %x, %X) viene effettuata tramite una union definita così nel file .h:

```c
typedef union u_numbers
{
    int            i;
    uintptr_t   u;     #rappresenta un tipo di dato per gli indirizzi di memoria, uso questo perchè sicuro conterrà la dimensione massima che è data dall'indirizzo di un puntatore
}    t_convtypenum;
```

- **ft_printf_utils_str.c** --> qui sono presenti le funzioni utili nella gestione delle stringhe. In particolare:
  
  ```c
  //ftpf_strdup: crea un duplicato della stringa s
  char    *ftpf_strdup(const char *s)
  
  //ftpf_strlen: calcola la lunghezza della stringa str
  size_t    ftpf_strlen(const char *str)
  
  //ftpf_toupper_str: trasforma la stringa str in caratteri maiuscoli
  void    ftpf_toupper_str(char *str)
  
  //ft_stradd: modifica la stringa str2 andando ad aggiungere la stringa str1
  //    all'inizio o alla fine a seconda del parametro i (0=inizio, 1=fine)
  char    *ft_stradd(const char *str1, char *str2, unsigned int i)
  
  //ftpf_strchr: cerca il carattere c all'interno di str partendo dall'inizio
  char    *ftpf_strchr(const char *str, int c)
  ```

**NB**: dato che per questo progetto NON ho utilizzato la libreria *libft*, le funzioni in comune che non sono dichiarate statiche sono state rinominate da *ft_* a *ftpf_* così da evitare problemi di linker in caso un domani si integrassero i sorgenti in *libft* facendo una libreria unica.
