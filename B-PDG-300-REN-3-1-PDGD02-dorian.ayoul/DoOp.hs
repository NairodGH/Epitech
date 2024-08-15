import System.Environment
import System.Exit
--------------------------------------------------------------------------------
myElem :: Eq a => a -> [a] -> Bool
myElem a [] = False
myElem a (b:c) = if (a == b) then True else myElem a c
--------------------------------------------------------------------------------
safeDiv :: Int -> Int -> Maybe Int
safeDiv x 0 = Nothing
safeDiv x y = Just (x `div` y)
--------------------------------------------------------------------------------
safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth (a:_) 0 = Just a
safeNth (_:a) x = safeNth a (x - 1)
--------------------------------------------------------------------------------
safeSucc :: Maybe Int -> Maybe Int
safeSucc (Just x) = Just (x + 1)
safeSucc Nothing = Nothing
--------------------------------------------------------------------------------
myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup a [] = Nothing
myLookup a (b:c) = if (a == fst b) then Just (snd b) else myLookup a c
--------------------------------------------------------------------------------
maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo func (Just a) Nothing = Nothing
maybeDo func Nothing (Just b) = Nothing
maybeDo func (Just a) (Just b) = Just (func a b)
--------------------------------------------------------------------------------
isInt :: [Char] -> Bool
isInt [] = True
isInt (a:b) = if (a >= '0' && a <= '9' || a == '-') then isInt b else False

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt a = if (isInt a) then Just (read a) else Nothing
--------------------------------------------------------------------------------
getLineLength :: IO Int
getLineLength = do
    x <- getLine
    return (length x)
--------------------------------------------------------------------------------
printAndGetLength :: String -> IO Int
printAndGetLength a = putStrLn a >> return (length a)
--------------------------------------------------------------------------------
myPrintSpace :: Int -> IO ()
myPrintSpace 0 = putStr("")
myPrintSpace x = putStr(" ") >> myPrintSpace (x - 1)

myPrintDash :: Int -> IO ()
myPrintDash 0 = putStr("")
myPrintDash x = putStr("-") >> myPrintDash (x - 1)

myPrint :: Int -> Int -> IO ()
myPrint 0 x = putStr("")
myPrint x y = if (x /= 1)
then putStr("|") >> myPrintSpace (y * 2) >> putStrLn("|") >> myPrint (x - 1) y
else putStr("+") >> myPrintDash (y * 2) >> putStrLn("+")

printBox :: Int -> IO ()
printBox x = if (x <= 0) then putStr("")
    else putStr("+") >> myPrintDash ((x - 1) * 2) >>
    putStrLn("+") >> myPrint (x - 1) (x - 1)
--------------------------------------------------------------------------------
putConcat :: Int -> IO String -> IO String
putConcat x a = if (x /= 0) then putConcat (x - 1) (mappend a getLine) else a

concatLines :: Int -> IO String
concatLines x = if (x < 0) then return "" else putConcat x (return [])
--------------------------------------------------------------------------------
getInt :: IO (Maybe Int)
getInt = do
    x <- getLine
    return (readInt x)
--------------------------------------------------------------------------------
doOp :: Int -> String -> Int -> String
doOp x o y = case o of
    "+" -> show (x + y) :: String
    "-" -> show (x - y) :: String
    "*" -> show (x * y) :: String
    "/" -> show (x `div` y) :: String
    "%" -> show (x `mod` y) :: String

checkError :: IO ()
checkError = do
    (x:o:y:_) <- getArgs
    if (isInt x == False || isInt y == False || o /= "+" && o /= "-"
        && o /= "*" && o /= "/" && o /= "%" || o == "/" && y == "0")
    then putStr "" >> exitWith (ExitFailure 84)
    else print (read (doOp (read x :: Int) o (read y :: Int)) :: Int)
--------------------------------------------------------------------------------
main :: IO ()
main = do
    a <- getArgs
    if (length a /= 3) then putStr "" >> exitWith (ExitFailure 84)
        else checkError