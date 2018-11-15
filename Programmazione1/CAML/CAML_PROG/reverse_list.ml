let rec rev l = match l with
     [] -> []
   | [x] -> [x]
   | x::(y::ys) -> (rev (y::ys)) @ [x];;   


rev [];;
rev [1];;
rev [1;2;3];;
