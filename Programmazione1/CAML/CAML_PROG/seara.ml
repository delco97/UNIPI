let separa l x = 
	let magg n = n>x
        in
	let min n = n<=x
	in
	(filter min l, filter magg l);;

separa [1;2;5;-1;3;-23;] 0;;
