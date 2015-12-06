
/*
 * Authors: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 */

#ifndef __utilities__
#define __utilities__

#include <vector>
#include <map>

/**
 *  Returns elapsed seconds past from the last call to timer rest.
 */
double cclock();

/**
 * Uniform the output of the message @p msg.
 * Version for a one line message.
 */
void print_msg(std::string msg);

/**
 * Uniform the output of the message @p msg.
 * Version for multi line message. Each line is an element of @p msg.
 */
void print_msg(std::vector<std::string> msg);

/**
 * Uniform the output of @p vector sequences.
 * @p space set the space reserved for each entry.
 */
template <typename T>
void print_sequence(std::vector<T> vec, unsigned int space = 3);

/**
 * Uniform the output of @p maps.
 * @p space set the space reserved for each entry.
 */
template <typename T,typename S>
void print_map(std::map<T,S> map, unsigned int space = 3);

#endif
