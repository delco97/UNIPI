let p x = x mod 2 = 0;;
let rec exist l p = match l with
	  [] -> false
	| x::xs -> if (p x) = true then true
                   else exist xs p;;

exist [] p = false;;
exist [1] p = false;;
exist [1;3;4;7;9] p = true;;
