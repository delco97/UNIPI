let rec drop n l = match (n,l) with
	  (n,l) when n<=0 -> l
	| (n,[]) when n>0 -> l
        | (n,x::xs) when n>0 -> drop(n-1) xs;;

drop 1 [1;2;3];;
drop 1 [1;2;3] = tl [1;2;3];; 
