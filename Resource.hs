{-# LANGUAGE ForeignFunctionInterface #-}
module Resource where
import Foreign.C.Types
import Data.Int
foreign export ccall bar :: Int16 -> IO Int16

bar :: Int16 -> IO Int16
--bar n = return (length (f n))
bar n = (return . fromIntegral . length . f) n

f :: Int16 -> [Int16]
f 0 = []
f n = n:(f (n-1))
