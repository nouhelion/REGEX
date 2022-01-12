# REGEX
Doing regex stuff in c++ / flex / bison

A regular expression (shortened as regex or regexp; also referred to as rational expression) is a sequence of characters that specifies a search pattern in text. Usually such patterns are used by string-searching algorithms for "find" or "find and replace" operations on strings, or for input validation. It is a technique developed in theoretical computer science and formal language theory.


Most formalisms provide the following operations to construct regular expressions.

=> Boolean "or"
A vertical bar separates alternatives. For example, gray|grey can match "gray" or "grey".

=> Grouping
Parentheses are used to define the scope and precedence of the operators (among other uses). For example, gray|grey and gr(a|e)y are equivalent patterns which both describe the set of "gray" or "grey".

=> Quantification
A quantifier after a token (such as a character) or group specifies how often that a preceding element is allowed to occur. The most common quantifiers are the question mark ?, the asterisk * (derived from the Kleene star), and the plus sign + (Kleene plus).
?	The question mark indicates zero or one occurrences of the preceding element. For example, colou?r matches both "color" and "colour".
*	The asterisk indicates zero or more occurrences of the preceding element. For example, ab*c matches "ac", "abc", "abbc", "abbbc", and so on.
+	The plus sign indicates one or more occurrences of the preceding element. For example, ab+c matches "abc", "abbc", "abbbc", and so on, but not "ac".
{n}	The preceding item is matched exactly n times.
{min,}	The preceding item is matched min or more times.
{,max}	The preceding item is matched up to max times.
{min,max}	The preceding item is matched at least min times, but not more than max times.
