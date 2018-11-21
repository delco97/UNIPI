let rec foldr f a l = match l with 
			[] -> a
			|x::xs -> f x (foldr f a xs);;
			
let rec filter p l = match l with 
			[] -> []
			|x::xs -> if (p x) then x::(filter p xs) else filter p xs;;
			

let rec forall p l = match l with 
			[] -> true
			|x::xs -> if(not p x) then false else forall p xs;;
			
let rec exists p l = match l with 
			[] -> false
			|x::xs -> if(p x) then true else exists p xs;;
			


let rec map f l = match l with
			[] -> []
			|x::xs -> (f x)::(map f xs);;