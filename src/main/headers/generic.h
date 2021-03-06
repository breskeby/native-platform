#ifndef __INCLUDE_GENERIC_H__
#define __INCLUDE_GENERIC_H__

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Marks the given result as failed, using the given error message
 */
extern void mark_failed_with_message(JNIEnv *env, const char* message, jobject result);

/*
 * Marks the given result as failed, using the given error message and the current value of errno/GetLastError()
 */
extern void mark_failed_with_errno(JNIEnv *env, const char* message, jobject result);

/*
 * Marks the given result as failed, using the given error message and error code
 */
extern void mark_failed_with_code(JNIEnv *env, const char* message, int error_code, jobject result);

typedef struct wchar_struct {
    // Not NULL terminated
    wchar_t* chars;
    // number of characters in the string
    size_t len;
    jstring source;
    JNIEnv *env;
} wchar_str;

/*
 * Converts the given Java string to a wchar_str. Should call wchar_str_free() when finished.
 *
 * Returns NULL on failure.
 */
extern wchar_str*
java_to_wchar_str(JNIEnv *env, jstring string, jobject result);

/*
 * Releases resources used by the given string.
 */
extern void wchar_str_free(wchar_str* str);

/*
 * Converts the given wchar_t string to a Java string.
 *
 * Returns NULL on failure.
 */
extern jstring wchar_to_java(JNIEnv* env, const wchar_t* chars, size_t len, jobject result);

/*
 * Converts the given Java string to a char_str. Should call free() when finished.
 *
 * Returns NULL on failure.
 */
extern char* java_to_char(JNIEnv *env, jstring string, jobject result);

/*
 * Converts the given NULL terminated char string to a Java string.
 *
 * Returns NULL on failure.
 */
extern jstring char_to_java(JNIEnv* env, const char* chars, jobject result);

#ifdef __cplusplus
}
#endif

#endif
