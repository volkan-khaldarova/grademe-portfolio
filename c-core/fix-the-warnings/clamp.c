int clamp(int v, int lo, int hi)
{
    // Kural: lo, hi'den büyükse sınırlar ters çevrilmiş kabul edilir 
    // ve her v değeri için lo dönmesi gerekir.
    if (lo > hi)
    {
        return lo;
    }

    // v değeri alt sınırdan küçükse lo döner
    if (v < lo)
    {
        return lo;
    }
    
    // v değeri üst sınırdan büyükse hi döner
    if (v > hi)
    {
        return hi;
    }

    // Değer sınırlar arasındaysa kendisi döner
    return v;
}

