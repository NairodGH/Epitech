module Operation where

sa :: [Int] -> [Int]
sa [] = []
sa [x] = [x]
sa (a:b:xs) = b : (a : xs)

sb :: [Int] -> [Int]
sb [] = []
sb [x] = [x]
sb (a:b:xs) = b : (a : xs)

sc :: [Int] -> [Int] -> ([Int], [Int])
sc [] [] = ([], [])
sc a [] = (sa a, [])
sc [] b = ([], sb b)
sc [a] [b] = ([a], [b])
sc a b = ((sa a), (sb b))

pa :: [Int] -> [Int] -> ([Int], [Int])
pa [] [] = ([], [])
pa a [] = (a, [])
pa a (b:bs) = (b : a, bs)

pb :: [Int] -> [Int] -> ([Int], [Int])
pb [] [] = ([], [])
pb [] b = ([], b)
pb (a:as) b = (as, a : b)

ra :: [Int] -> [Int]
ra [] = []
ra [x] = [x]
ra (x:xs) = mappend xs [x]

rb :: [Int] -> [Int]
rb [] = []
rb [x] = [x]
rb (x:xs) = mappend xs [x]

rr :: [Int] -> [Int] -> ([Int], [Int])
rr [] [] = ([], [])
rr a [] = (ra a, [])
rr [] b = ([], rb b)
rr [a] [b] = ([a], [b])
rr a b = ((ra a), (rb b))

rra :: [Int] -> [Int]
rra [] = []
rra [x] = [x]
rra (x:xs) = last xs : (mappend [x] (init xs))

rrb :: [Int] -> [Int]
rrb [] = []
rrb [x] = [x]
rrb (x:xs) = last xs : (mappend [x] (init xs))

rrr :: [Int] -> [Int] -> ([Int], [Int])
rrr [] [] = ([], [])
rrr a [] = (rra a, [])
rrr [] b = ([], rrb b)
rrr [a] [b] = ([a], [b])
rrr a b = ((rra a), (rrb b))
