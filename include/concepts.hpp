#pragma once
#include <concepts>
#include <cstddef>

template <typename C>
concept Stackable = requires(C c, typename C::value_type v) {
    { c.PushBack(v) } -> std::same_as<void>;
    { c.PopBack() } -> std::same_as<void>;
    { c.Back() } -> std::same_as<typename C::reference>;
    { c.GetLength() } -> std::convertible_to<size_t>;
};

template <typename C>
concept Queueable = requires(C c, typename C::value_type v) {
    { c.PushBack(v) } -> std::same_as<void>;
    { c.PopFront() } -> std::same_as<void>;
    { c.Front() } -> std::same_as<typename C::reference>;
    { c.Back() } -> std::same_as<typename C::reference>;
    { c.GetLength() } -> std::convertible_to<size_t>;
};

template <typename C>
concept Dequeable = requires(C c, typename C::value_type v) {
    { c.PushBack(v) } -> std::same_as<void>;
    { c.PushFront(v) } -> std::same_as<void>;
    { c.PopBack() } -> std::same_as<void>;
    { c.PopFront() } -> std::same_as<void>;
    { c.Front() } -> std::same_as<typename C::reference>;
    { c.Back() } -> std::same_as<typename C::reference>;
    { c.GetLength() } -> std::convertible_to<size_t>;
};