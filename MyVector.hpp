/* Define all your MyVector-related functions here.
 * Also, define the swap function here.
 * You do not need to include the h file.
 * It included this file at the bottom.
 */

void get_identity(string &my_id) 
{
    my_id = "rjstrd";
}

template <typename T>
void MySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// We're giving you this one for free
// and as a guide for the syntax.
template <typename T>
MyVector<T>::~MyVector()
{
    delete[] m_data;
}


// Another example: remember when writing an implementation in hpp,
// return type first, then scope just before the function name.
template <typename T>
T & MyVector<T>::at(int index)
{
    if(index > data_size)
    {
        throw std::out_of_range("invalid index");
    }
    else
    {
        return m_data[index];
    }
}

template <typename T>
T & MyVector<T>::operator[](int i)
{
    return m_data[i];
}
 
template <typename T>
MyVector<T>::MyVector()
{
    m_data = nullptr;
    reserved_size = 0;
    data_size = 0;
}

template <typename T>
T & MyVector<T>::front()
{
    return m_data[0];
}

template <typename T>
T & MyVector<T>::back()
{
    return m_data[size() - 1];
}

template <typename T>
int MyVector<T>::size()
{
    return data_size;
}

template <typename T>
int MyVector<T>::capacity()
{
    return reserved_size;
}

template <typename T>
void MyVector<T>::pop_back()
{
    if(size() > 0)
    {
        m_data[size() - 1].~T();
        data_size--;
    }
    if (size() < (reserved_size / 4))
    {
        shrink_to_fit();
    }
}

template <typename T>
void MyVector<T>::push_back(const T &x)
{
    m_data[size() + 1] = x;
    data_size++;
    if (data_size == reserved_size)
    {
        reserve(capacity() * 2);
    }
}

template <typename T>
void MyVector<T>::reserve(int new_cap)
{
    if (new_cap > capacity())
    {
        T* tempData = new T[new_cap];
        for (int i = 0; i < size(); i++)
        {
            tempData[i] = m_data[i];
        }

        reserved_size = new_cap;
        delete[] m_data;
        m_data = tempData;
    }  
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T> &source)
{
    data_size = source.data_size;
    reserved_size = source.reserved_size;
    T* tempData = new T[reserved_size];
    for (int i = 0; i < size(); i++)
    {
        m_data[i] = source.m_data[i];
    }
}

template <typename T>
MyVector<T> & MyVector<T>::operator=(const MyVector<T> &source)
{
    data_size = source.data_size;
    reserved_size = source.reserved_size;
    T* tempData = new T[reserved_size];
    for (int i = 0; i < size(); i++)
    {
        tempData[i] = source.m_data[i];
    }
    delete[] m_data;
    m_data = tempData;
    return *this;
}

template <typename T>
void MyVector<T>::shrink_to_fit()
{
    reserved_size = size() * 2;
}

template <typename T>
void MyVector<T>::assign(int count, const T &value)
{
    delete[] m_data;
    m_data = new T[count];
    for (int i = 0; i < count; i++)
    {
        m_data[i] = value;
    }
}

template <typename T>
void MyVector<T>::clear()
{
    delete[] m_data;
    m_data = nullptr;
    data_size = 0;
    reserved_size = 0;
}

template <typename T>
void MyVector<T>::insert(int i, const T &x)
{
    for(int k = (size() - 1); k >= i; k--)
    {
        m_data[k] = m_data[k - 1];
    }
    m_data[i] = x;
    if (data_size == reserved_size)
    {
        reserve(capacity() * 2);
    }
}

template <typename T>
void MyVector<T>::erase(int i)
{
    for(int k = i; k < size(); k++)
    {
        m_data[k] = m_data[k + 1];
    }
    m_data[size() - 1].~T();
    data_size--;

    if (size() < (reserved_size / 4))
    {
        shrink_to_fit();
    }
}