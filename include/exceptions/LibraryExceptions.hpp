#ifndef LIBRARY_EXCEPTION_HPP
#define LIBRARY_EXCEPTION_HPP

#include <stdexcept>
#include <string>

class LibraryException : public std::runtime_error
{
public:
    explicit LibraryException(const std::string& message)
        : std::runtime_error(message) {}
};

class SongNotFoundException : public LibraryException
{
public:
    explicit SongNotFoundException(const std::string& message)
        :LibraryException(message) {}
};

class PlaylistNotFoundException : public LibraryException
{
public:
    explicit PlaylistNotFoundException(const std::string& message)
        :LibraryException(message) {}
};

class InvalidOperationException : public LibraryException
{
public:
    explicit InvalidOperationException(const std::string& message)
        :LibraryException(message) {}
};

class InvalidDateException : public LibraryException
{
public:
    explicit InvalidDateException(const std::string& message)
        : LibraryException(message) {}
};

class DuplicateSongException : public LibraryException
{
public:
    explicit DuplicateSongException(const std::string& message)
        :LibraryException(message) {}
};

class DuplicateUsernameException : public LibraryException
{
public:
    explicit DuplicateUsernameException(const std::string& message)
        :LibraryException(message) {}
};

class InvalidRatingException : public LibraryException
{
public:
    explicit InvalidRatingException(const std::string& message)
        :LibraryException(message) {}
};

#endif