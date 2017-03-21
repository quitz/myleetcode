
// implement the Comparable template here
template<typename Derived> struct Comparable{
    bool operator==(const Comparable<Derived>& o1) const noexcept{
        const Derived& d1 = static_cast<const Derived*>(o1);
        const Derived& d2 = static_cast<const Derived*>(*this);
        
        return d1.value == d2.value;
    }
    
    bool operator>=(const Comparable<Derived>& o1) const noexcept{
        const Derived& d1 = static_cast<const Derived*>(o1);
        const Derived& d2 = static_cast<const Derived*>(*this);
        
        return d1.value >= d2.value;
    }
    bool operator<=(const Comparable<Derived>& o1) const noexcept{
        const Derived& d1 = static_cast<const Derived*>(o1);
        const Derived& d2 = static_cast<const Derived*>(*this);
        
        return d1.value <= d2.value;
    }
    bool operator!=(const Comparable<Derived>& o1) const noexcept{
        const Derived& d1 = static_cast<const Derived*>(o1);
        const Derived& d2 = static_cast<const Derived*>(*this);
        
        return d1.value != d2.value;
    }
    bool operator>(const Comparable<Derived>& o1) const noexcept{
        const Derived& d1 = static_cast<const Derived*>(o1);
        const Derived& d2 = static_cast<const Derived*>(*this);
        
        return d1.value > d2.value;
    }
    bool operator<(const Comparable<Derived>& o1) const noexcept{
        const Derived& d1 = static_cast<const Derived*>(o1);
        const Derived& d2 = static_cast<const Derived*>(*this);
        
        return d1.value < d2.value;
    }
}