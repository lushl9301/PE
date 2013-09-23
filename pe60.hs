import Data.Numbers.Primes (isPrime)

minus [] _ = []
minus xs [] = xs
minus l1@(x:xs) l2@(y:ys)
    | x > y = minus l1 ys
    | x < y = x : minus xs l2
    | otherwise = minus xs l2

findPrime m = 2 : sieve [3,5 .. m] where
  sieve (p:xs)
    | p*p > m = p : xs
    | otherwise = p : sieve (xs `minus` [p*p, p*p+2*p ..])
                  
--I cried for this sieve method implementation...

isConcatPrime x y = (isPrime $ readInt $ show x ++ show y)
                    && (isPrime & readInt $ show y ++ show x)
  where readInt = read :: String -> Int
        
