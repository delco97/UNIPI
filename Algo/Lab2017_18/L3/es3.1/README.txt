***Come esegure progrmma con file di input***
La directory contiene input diversi (file .in) insieme agli output attesi
(file .out). Ad esempio: 100.in contiene 2 array di lunghezza cento, ed `e
possibile usarlo come input al programma utilizzando la redirezione dell’input
vista a lezione:
./esercizio.o < 100.in
Si provi a lanciare il programma su input diversi e per ogni input si
controlli che l’output sia giusto confrontandolo col valore nel rispettivo file
.out, che `e possibile stampare sul terminale col comando cat, ad esempio:
cat 100.out
45

****Come misurare tempo di esecuzione****
Infine, si provi a misurare quanto tempo impiega il programma su input
diversi utilizzando il comando time, che restituisce in output il tempo impiegato
dal programma, ad esempio:
time ./esercizio.o < 100.in
45
real 0.066 user 0.005 sys 0.003 pcpu 11.07
Come varia il tempo impiegato a seconda della dimensione dell’array?