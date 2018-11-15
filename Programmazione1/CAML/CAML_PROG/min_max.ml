let rec foldr f a l = match l with
	  [] -> a
	| x::xs -> f x (foldr f a xs);;

let max l = 
   let f a b = if a > b then a
	       else b
   in match l with
        | x::xs -> foldr f x l;;

let min l = 
   let f a b = if a < b then a
	       else b
   in match l with
        | x::xs -> foldr f x l;;

let min_max l = match l with
	x::xs -> (min l, max l);;

min_max [0;1;-1;-10;5];;
