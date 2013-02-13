#ifndef BINARYMASK_H
#define BINARYMASK_H

class BinaryMask
{
public:
    BinaryMask();
    ~BinaryMask();
    void setTrueAt(const int &index);
    bool getValueAt(const int &index);
    void clear();
private:
    int mainMask;
};

#endif // BINARYMASK_H
