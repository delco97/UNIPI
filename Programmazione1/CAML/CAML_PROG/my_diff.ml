let rec canc l el = match l with
	  [] -> []
	| [x] -> if x = el then [] else [x]
	| x::(y::ys) ->  if x = el then y::ys
			 else x::(canc (y::ys) el);;

let rec diff l1 l2 = match (l1,l2) with
	  ([],[]) -> []
	| (x::xs,[]) -> x::xs
	| ([],x::xs) -> []
	| (x::xs, y::ys) -> diff (canc (x::xs) y) ys;;				

diff [] [];;
diff [2] [];;
diff [] [3];;
diff [2;3;3] [2];;
diff [2;3;2] [2];;
diff [2;3;2;5;5] [2;5];;
