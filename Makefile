all:
	bazel build //lash:lash
t:
	bazel test --test_output=errors test/...
