let rec my_filter p l = match l with
	  [] -> []
	| x::xs -> if p x then my_filter p xs
		   else x::(my_filter p xs);; 

let even x = (x mod 2) = 0
in my_filter even [1;2;3;4;5;6];;
