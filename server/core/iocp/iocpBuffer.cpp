#include "pch.h"
#include "iocpBuffer.h"

IocpBuffer::IocpBuffer(size_t capacity)
    : mCapacity(capacity)
    , mReadPos(0)
    , mWritePos(0)
{
    mBuffer = std::make_unique<char[]>(capacity);
}

bool IocpBuffer::Write(const char* data, size_t size)
{
    if (data == nullptr || size == 0)
        return false;

    if (GetRemainSize() < size)
        return false;

    size_t firstWrite = __min(size, mCapacity - GetWritePosWithoutMod());
    memcpy(mBuffer.get() + GetWritePosWithoutMod(), data, firstWrite);

    if (firstWrite < size)
    {
        memcpy(mBuffer.get(), data + firstWrite, size - firstWrite);
    }

    mWritePos = (mWritePos + size) % mCapacity;
    return true;
}

bool IocpBuffer::Read(char* dest, size_t size)
{
    if (dest == nullptr || size == 0)
        return false;

    if (GetStoredSize() < size)
        return false;

    size_t firstRead = __min(size, mCapacity - GetReadPosWithoutMod());
    memcpy(dest, mBuffer.get() + GetReadPosWithoutMod(), firstRead);

    if (firstRead < size)
    {
        memcpy(dest + firstRead, mBuffer.get(), size - firstRead);
    }

    mReadPos = (mReadPos + size) % mCapacity;
    return true;
}

void IocpBuffer::Read(size_t size)
{
    if (GetStoredSize() >= size)
    {
        mReadPos = (mReadPos + size) % mCapacity;
    }
}

void IocpBuffer::Clear()
{
    mReadPos = 0;
    mWritePos = 0;
}

char* IocpBuffer::GetWritePtr()
{
    return mBuffer.get() + GetWritePosWithoutMod();
}

char* IocpBuffer::GetReadPtr()
{
    return mBuffer.get() + GetReadPosWithoutMod();
}

size_t IocpBuffer::GetContinuousWriteSize() const
{
    if (GetWritePosWithoutMod() >= GetReadPosWithoutMod())
    {
        if (GetReadPosWithoutMod() == 0)
            return mCapacity - GetWritePosWithoutMod();
        else
            return mCapacity - GetWritePosWithoutMod();
    }
    else
    {
        return GetReadPosWithoutMod() - GetWritePosWithoutMod();
    }
}

size_t IocpBuffer::GetStoredSize() const
{
    if (mWritePos >= mReadPos)
        return mWritePos - mReadPos;
    else
        return mCapacity - (mReadPos - mWritePos);
}

size_t IocpBuffer::GetRemainSize() const
{
    return mCapacity - GetStoredSize() - 1;
}

void IocpBuffer::MoveWritePos(size_t size)
{
    mWritePos = (mWritePos + size) % mCapacity;
}

void IocpBuffer::MoveReadPos(size_t size)
{
    mReadPos = (mReadPos + size) % mCapacity;
}

size_t IocpBuffer::GetReadPos() const
{
    return mReadPos;
}

size_t IocpBuffer::GetWritePos() const
{
    return mWritePos;
}

size_t IocpBuffer::GetReadPosWithoutMod() const
{
    return mReadPos % mCapacity;
}

size_t IocpBuffer::GetWritePosWithoutMod() const
{
    return mWritePos % mCapacity;
}