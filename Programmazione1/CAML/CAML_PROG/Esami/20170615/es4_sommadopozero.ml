
let sommadopozero lis = 
	let f x (trovato,sum) =
		if trovato then (true,sum)
		else if x = 0 then (true,sum)
		     else (false,sum+x)
	in
	let (t,s) = foldr f (false,0) lis
	in
	if t then s else 0;; 

sommadopozero [1;2;0;3;2];;
sommadopozero [];;
sommadopozero [1;2;3];;
sommadopozero [0;2];;
sommadopozero [0;0;1];;
