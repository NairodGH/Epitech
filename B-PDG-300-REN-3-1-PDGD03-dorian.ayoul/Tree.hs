module Tree where
--------------------------------------------------------------------------------
data Tree a = Empty | Node (Tree a) a (Tree a) deriving Show
--------------------------------------------------------------------------------
addInTree :: Ord a => a -> Tree a -> Tree a
addInTree a Empty = Node Empty a Empty
addInTree a (Node b c d) = if (a < c)
    then Node (addInTree a b) c d
    else Node b c (addInTree a d)
--------------------------------------------------------------------------------
instance Functor Tree where
    fmap (func) Empty = Empty
    fmap (func) (Node a b c) = Node (fmap func a) (func b) (fmap func c)
--------------------------------------------------------------------------------
listToTree :: Ord a => [a] -> Tree a
listToTree [] = Empty
listToTree (a:b) = addInTree a (listToTree b)
--------------------------------------------------------------------------------
treeToList :: Tree a -> [a]
treeToList Empty = []
treeToList (Node a b c) = treeToList a ++ [b] ++ treeToList c
--------------------------------------------------------------------------------
treeSort :: Ord a => [a] -> [a]
treeSort [] = []
treeSort a = treeToList (listToTree a)
--------------------------------------------------------------------------------
instance Foldable Tree where
    foldMap func Empty = mempty
    foldMap func (Node a b c) =
        foldMap func a `mappend` func b `mappend` foldMap func c