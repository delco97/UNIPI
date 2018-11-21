let rec len l = match l with
	  [] -> 0
	| [x] -> 1
	| x::xs -> 1 + len xs;;

let rec rev2 l = match l with
	  [] -> []
	| [x] -> [x]
	| y::x::xs when (len l) <> 2 -> y::x::xs
	| y::x::xs when (len l) = 2 ->  (rev2 (x::xs)) @ [y];;


rev2 [];;
rev2 [1];;
rev2 [1;2];;
rev2 [1;2;3];;
