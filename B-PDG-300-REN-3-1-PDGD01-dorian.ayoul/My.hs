mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = if (x < 0) then True else False

myAbs :: Int -> Int
myAbs x = if (x < 0) then x * (-1) else x

myMin :: Int -> Int -> Int
myMin x y = if (x < y) then x else y

myMax :: Int -> Int -> Int
myMax x y = if (x > y) then x else y

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead (a:_) = a
myHead (_) = error "[ERROR] List is empty"

myTail :: [a] -> [a]
myTail (_:a) = a
myTail (_) = error "[ERROR] List is empty"

myLength :: [a] -> Int
myLength [] = 0
myLength (_:a) = myLength a + 1

myNth :: [a] -> Int -> a
myNth [] _ = error "[ERROR] Wrong index or list is empty"
myNth (a:_) 0 = a
myNth (_:a) x = myNth a (x - 1)

myTake :: Int -> [a] -> [a]
myTake x [] = if (x > 0) then [] else error "[ERROR] Wrong index or list empty"
myTake x (a:b) = if (x /= 1) then a : myTake (x - 1) b else a : []

myDrop :: Int -> [a] -> [a]
myDrop x [] = if (x > 0) then [] else error "[ERROR] Wrong index or list empty"
myDrop x (a:b) = if (x == 1) then b else myDrop (x - 1) b

myAppend :: [a] -> [a] -> [a]
myAppend [] a = a
myAppend (a:b) c = a : myAppend b c

myReverse :: [a] -> [a]
myReverse [] = []
myReverse a = myLast a : myReverse (myInit a)

myInit :: [a] -> [a]
myInit [] = error "[ERROR] List is empty"
myInit a = if (myLength(a) == 1) then [] else myTake (myLength(a) - 1) a

myLast :: [a] -> a
myLast [] = error "[ERROR] List is empty"
myLast a = myNth a (myLength(a) - 1)

myZip :: [a] -> [b] -> [(a, b)]
myZip [] a = []
myZip a [] = []
myZip (a:b) (c:d) = (a,c) : myZip b d

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((a, b):c) = (a : d, b : e)
    where (d, e) = myUnzip c

myMap :: (a -> b) -> [a] -> [b]
myMap func [] = []
myMap func (a:b) = func a : myMap func b

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter func [] = []
myFilter func (a:b) = if (func a) then a : myFilter func b else myFilter func b

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl func a [] = a
myFoldl func a (b:c) = myFoldl func (func a b) c

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr func a [] = a
myFoldr func a (b:c) = myFoldr func (func (myLast (b:c)) a) (myInit (b:c))

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition func [] = ([], [])
myPartition func (a:b) =
    if (func a) then (a : true, false) else (true, a : false)
    where (true, false) = myPartition func b