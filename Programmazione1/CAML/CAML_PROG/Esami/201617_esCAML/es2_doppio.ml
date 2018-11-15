let rec doppio l = match l with
	[] -> true
	| [x] -> true
	| x::y::ys -> if y = (x*2) then doppio ys
		      else false;;


doppio [];;
doppio [1];;
doppio [2;1];;
doppio [1;2];;
