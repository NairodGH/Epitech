/*
** EPITECH PROJECT, 2022
** Errors.hpp
** File description:
** Errors
*/

#pragma once

#include <string>

class NasaError : public std::exception
{
    public:
        NasaError(std::string const &message, std::string const &component = "Unknown");
        virtual ~NasaError() = default;
        std::string const &getComponent() const;
        const char *what() const noexcept override;
    private:
        std::string _message;
        std::string _component;
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message, std::string const &component = "Unknown");
        virtual ~MissionCriticalError() = default;
};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message, std::string const &component = "Unknown");
        virtual ~LifeCriticalError() = default;
};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message, std::string const &component = "Unknown");
        virtual ~UserError() = default;
};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message);
        virtual ~CommunicationError() = default;
};