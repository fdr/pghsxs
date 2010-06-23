{-# LANGUAGE ForeignFunctionInterface #-}
module HelloPostgres where
import Foreign.C.Types
import Data.Int
foreign export ccall foo :: Int16 -> IO Int16

foo :: Int16 -> IO Int16
--foo n = return (length (f n))
foo n = (return . fromIntegral . length . f) n

f :: Int16 -> [Int16]
f 0 = []
f n = n:(f (n-1))
