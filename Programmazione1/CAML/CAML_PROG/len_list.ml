let rec len l = match l with
	[] -> 0
	| x::xs -> 1 + len xs;;
len [] = 0;;
len [2;53;12;12] = 4;;
