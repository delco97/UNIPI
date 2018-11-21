include "Z:/Desktop/Programazione1_lab/CAML/CAML_PROG/sup2.ml";;
let listasomme l = 
	let f a (ris,sum,zeri) = 
		if (zeri = 0) then 
			if (a = 0) then (ris,0,1)
			else (ris,0,0)
		else
			if (a = 0) then (sum::ris,0,1)
			else (ris,sum+a,1)
	in
	let (r,s,z) = foldr f ([],0,0) l in r;;
	
listasomme [];;
listasomme [1;2;3];;
listasomme [1;2;0];;
listasomme [0;2;1;0];;
listasomme [0;1;0;2;0];;
