let rec my_map f l = match l with
	  [] -> []
	| x::xs -> f x::(my_map f xs);;

let succ a = a + 1
in my_map succ [1;2;3;4];;
