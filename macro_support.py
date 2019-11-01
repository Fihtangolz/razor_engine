import clang.cindex
import typing

clang.cindex.Config.set_library_file('/usr/lib/llvm-8/lib/libclang.so')

index = clang.cindex.Index.create()
translation_unit = index.parse('/home/mrsmith/Desktop/3d_engine/razor-phantom/src/main.cpp', args=['-std=c++17'])

def filter_node_list_by_node_kind(
        nodes: typing.Iterable[clang.cindex.Cursor],
        kinds: list
) -> typing.Iterable[clang.cindex.Cursor]:
    result = []

    for i in nodes:
        if i.kind in kinds:
            result.append(i)

    return result

def filter_node_list_by_file(
        nodes: typing.Iterable[clang.cindex.Cursor],
        file_name: str
) -> typing.Iterable[clang.cindex.Cursor]:
    result = []

    for i in nodes:
        if i.location.file.name == file_name:
            result.append(i)

    return result

all_classes = filter_node_list_by_node_kind(translation_unit.cursor.get_children(), [clang.cindex.CursorKind.FUNCTION_DECL])

filtered = filter_node_list_by_file(all_classes, '/home/mrsmith/Desktop/3d_engine/razor-phantom/src/main.cpp')

for i in filtered:
    print(i.spelling)