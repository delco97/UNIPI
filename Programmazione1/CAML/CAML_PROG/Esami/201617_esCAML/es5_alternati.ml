let alternati l =
	let rec alternati_aux l1 a b = match l1 with
		  [] -> true
		| [x] -> x = a
		| x::y::ys -> if x=a & y=b then alternati_aux ys a b else false
	in match l with
		  [] -> true
		| [z] -> true
		| z::h::hs -> alternati_aux hs z h;;

alternati [];;
alternati [3];;
alternati [4;5;7];;
alternati [4;8;4];;
alternati [3;5;3;5];;
alternati [3;5;3;5;5];;
