 let rec len l = match l with
	  [] -> 0
	| [x] -> 1
	| x::xs -> 1 + len xs;;

len [];;
len [1];;
len [(1,"a");(1,"b")];;