let compose f g x = f(g x);;
let f x = 3*x;;
let g x = x+1;;

compose f g 3;;
