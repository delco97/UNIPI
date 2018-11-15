include "Z:/Desktop/Programazione1_lab/CAML/CAML_PROG/sup2.ml";;
let rec inizio l n =
	let rec ismember l1 a = match l1 with
		  [] -> false
		| x::xs -> if x = a then true else ismember xs a
	in match l with
		  [] -> []
		| w::ws when w = n -> []
		| w::ws when w <> n & ismember ws n -> w::(inizio ws n)
		| w::ws when w <> n & (ismember ws n) = false -> [];;
 
inizio [] 4;;
inizio [1;4] 4;;
inizio [4;4;4] 4;;
inizio [1;2;4;0;4] 4;;
inizio [1;2;3] 4;;
inizio [1;2;3] 3;;
