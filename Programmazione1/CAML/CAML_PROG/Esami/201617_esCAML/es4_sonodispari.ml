let rec sonodispari l = match l with
	  [] -> false
	| [x] -> true
	| x::xs -> if (sonodispari xs) then false else true;;

sonodispari [];;
sonodispari [1];;
sonodispari [1;2];;
sonodispari [1;1;1];;
sonodispari [1;1;1;1];;
