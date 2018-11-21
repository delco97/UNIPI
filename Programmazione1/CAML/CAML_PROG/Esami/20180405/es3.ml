let prec lis n m = 
	let f a (succ,ok) =
		if !ok then (a,false)
		else
		  if a=n & succ<>m then (a,false)
		  else (a,true)

	in
	let (s,r) = foldr f (m+1,true) lis
	in r;;

prec [1;2;1;2] 1 2;;
prec [1;2;2;2] 1 2;;
prec [] 1 2;;
prec [1] 1 2;;
prec [2;1;2] 1 2;;
