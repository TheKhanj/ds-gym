#ifndef RESULT_TYPE
#	define RESULT_TYPE(T, Error, suffix)                                        \
		typedef struct {                                                           \
			T value;                                                                 \
			Error err;                                                               \
		} result_##suffix##_t;                                                     \
                                                                               \
		static inline result_##suffix##_t suffix##_ok(T v) {                       \
			return (result_##suffix##_t){.value = v, .err = (Error)0};               \
		}                                                                          \
                                                                               \
		static inline result_##suffix##_t suffix##_err(Error e) {                  \
			return (result_##suffix##_t){.err = e};                                  \
		}
#endif
