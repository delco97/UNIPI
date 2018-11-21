include "Z:/Desktop/Programazione1_lab/CAML/CAML_PROG/sup2.ml";;

let primidiliste lis = 
	let p a = a <> []
	in
	let l1 = filter p lis
	in
	map hd l1;;

primidiliste [[];[1];[2;3];[];[4]];;
