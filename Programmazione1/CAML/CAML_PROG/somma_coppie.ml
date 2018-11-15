let somma_coppie l = 
	let f (x,y) = x+y
	in map f l;;

somma_coppie [(1,2);(2,4);(5,6);(7,8)];;
