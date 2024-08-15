module Main where

import System.Environment
import System.Exit

import Operation

isSorted :: [Int] -> Bool
isSorted [] = False
isSorted [x] = True
isSorted (x:y:xs) = if (x <= y) then isSorted (y:xs) else False

doOperationRev :: String -> [Int] -> [Int] -> ([Int], [Int])
doOperationRev "rra" a b = (rra a, b)
doOperationRev "rrb" a b = (a, rrb b)
doOperationRev "rrr" a b = rrr a b

doOperation :: String -> [Int] -> [Int] -> ([Int], [Int])
doOperation "sa" a b = (sa a, b)
doOperation "sb" a b = (a, sa b)
doOperation "sc" a b = sc a b
doOperation "pa" a b = pa a b
doOperation "pb" a b = pb a b
doOperation "ra" a b = (ra a, b)
doOperation "rb" a b = (a, rb b)
doOperation "rr" a b = rr a b
doOperation op a b = doOperationRev op a b

process :: [String] -> ([Int], [Int]) -> ([Int], [Int])
process [] lists = (fst lists, snd lists)
process op lists =
    process (tail op) (doOperation (head op) (fst lists) (snd lists))

result :: ([Int], [Int]) -> IO ()
result lists = if (isSorted (fst lists) && length (snd lists) == 0)
               then putStrLn "OK"
               else putStr "KO : " >> print lists

mainLoop :: [Int] -> [Char] -> IO ()
mainLoop [] _ = putStrLn "[ERROR] No arguments" >> exitWith (ExitFailure 84)
mainLoop x y = result (process (words y) (x, []))

checkOps :: [String] -> Bool
checkOps [] = True
checkOps (a:b) =
    if (a /= "sa" && a /= "sb" && a /= "sc" && a /= "pa" && a /= "pb"
    && a /= "ra" && a /= "rb" && a /= "rr" && a /= "rra" && a /= "rrb" &&
    a /= "rrr")
        then False else checkOps b

isNumber :: String -> Bool
isNumber str =
    case (reads str) :: [(Int, String)] of
      [(_, "")] -> True
      _         -> False

checkArgs :: [String] -> Bool
checkArgs [] = True
checkArgs (a:xs) = if isNumber a then checkArgs xs else False

main :: IO ()
main = do
    numbers <- getArgs
    operations <- getLine
    if (checkArgs numbers == False || checkOps (words operations) == False)
        then putStrLn "[ERROR] Bad arguments or operations"
        >> exitWith (ExitFailure 84)
        else mainLoop (map read numbers :: [Int]) operations
