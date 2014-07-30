/*
 * Agate JNI helper functions.
 *
 * This file may be included by C or C++ code
 */
#ifndef NATIVEHELPER_AGATE_JNI_H_
#define NATIVEHELPER_AGATE_JNI_H_

#include "jni.h"
#include "cutils/log.h"
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Tests if data can flow
 */
bool agateJniCanFlow(JNIEnv* env, int from, int to);

/*
 * Get a policy representing the current process
 */
int agateJniGetCurrentProcessPolicy(JNIEnv* env);

/*
 * Gets the Policy on a socket
 */
int agateJniGetSocketPolicy(JNIEnv* env, jobject fd);

/*
 * Gets the Policy on a StringObject
 */
int agateJniGetStringPolicy(JNIEnv* env, jobject obj);

/*
 * Gets the Policy on an ArrayObject
 */
int agateJniGetArrayPolicy(JNIEnv* env, jobject obj);

/*
 * Encodes a policy as a stream of bytes (Serializes)
 */
char* agateJniEncodePolicy(JNIEnv* env, int* size, int tag);

/*
 * De-codes a policy from a stream of bytes (De-serialization)
 */
int agateJniDecodePolicy(JNIEnv* env, char* p);

/*
 * Adds policy to a socket
 */
void agateJniAddSocketPolicy(JNIEnv* env, jobject fd, int tag);

/*
 * Adds policy to a StringObject
 */
void agateJniAddStringPolicy(JNIEnv* env);

/*
 * Adds policy to an ArrayObject
 */
void agateJniAddArrayPolicy(JNIEnv* env, jobject obj, int tag);

/* Get the identity of the logged in user */
int agateJniGetCertificate(JNIEnv* env);

void agateJniPrintPolicy(int tag);

#ifdef __cplusplus
}
#endif

#endif  /* NATIVEHELPER_AGATE_JNI_H_ */
