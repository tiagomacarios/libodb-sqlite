cmake_minimum_required(VERSION 3.0)
project(odb-sqlite)

set(ODBSQLITE_INCLUDE
    odb/sqlite/auto-handle.hxx
    odb/sqlite/binding.hxx
    odb/sqlite/blob-stream.hxx
    odb/sqlite/blob.hxx
    odb/sqlite/connection-factory.hxx
    odb/sqlite/connection.hxx
    odb/sqlite/connection.ixx
    odb/sqlite/container-statements.hxx
    odb/sqlite/container-statements.txx
    odb/sqlite/database.hxx
    odb/sqlite/database.ixx
    odb/sqlite/error.hxx
    odb/sqlite/exceptions.hxx
    odb/sqlite/forward.hxx
    odb/sqlite/no-id-object-result.hxx
    odb/sqlite/no-id-object-result.txx
    odb/sqlite/no-id-object-statements.hxx
    odb/sqlite/no-id-object-statements.txx
    odb/sqlite/polymorphic-object-result.hxx
    odb/sqlite/polymorphic-object-result.txx
    odb/sqlite/polymorphic-object-statements.hxx
    odb/sqlite/polymorphic-object-statements.txx
    odb/sqlite/prepared-query.hxx
    odb/sqlite/query-dynamic.hxx
    odb/sqlite/query-dynamic.ixx
    odb/sqlite/query-dynamic.txx
    odb/sqlite/query.hxx
    odb/sqlite/query.ixx
    odb/sqlite/query.txx
    odb/sqlite/section-statements.hxx
    odb/sqlite/section-statements.txx
    odb/sqlite/simple-object-result.hxx
    odb/sqlite/simple-object-result.txx
    odb/sqlite/simple-object-statements.hxx
    odb/sqlite/simple-object-statements.ixx
    odb/sqlite/simple-object-statements.txx
    odb/sqlite/sqlite-types.hxx
    odb/sqlite/statement-cache.hxx
    odb/sqlite/statement-cache.txx
    odb/sqlite/statement.hxx
    odb/sqlite/statements-base.hxx
    odb/sqlite/stream.hxx
    odb/sqlite/text-stream.hxx
    odb/sqlite/text.hxx
    odb/sqlite/tracer.hxx
    odb/sqlite/traits-calls.hxx
    odb/sqlite/traits.hxx
    odb/sqlite/transaction-impl.hxx
    odb/sqlite/transaction-impl.ixx
    odb/sqlite/transaction.hxx
    odb/sqlite/transaction.ixx
    odb/sqlite/version.hxx
    odb/sqlite/view-result.hxx
    odb/sqlite/view-result.txx
    odb/sqlite/view-statements.hxx
    odb/sqlite/view-statements.txx

    odb/sqlite/details/config.hxx
    odb/sqlite/details/conversion.hxx
    odb/sqlite/details/export.hxx
    odb/sqlite/details/options.hxx
    odb/sqlite/details/options.ixx
)

if(WIN32)
    set(ODB_INCLUDE
        ${ODB_INCLUDE}
        odb/sqlite/details/config.h
    )
ENDIF()

set(ODBSQLITE_SRC
    odb/sqlite/connection.cxx
    odb/sqlite/connection-factory.cxx
    odb/sqlite/database.cxx
    odb/sqlite/error.cxx
    odb/sqlite/exceptions.cxx
    odb/sqlite/prepared-query.cxx
    odb/sqlite/query.cxx
    odb/sqlite/query-dynamic.cxx
    odb/sqlite/query-const-expr.cxx
    odb/sqlite/simple-object-statements.cxx
    odb/sqlite/statement.cxx
    odb/sqlite/statements-base.cxx
    odb/sqlite/statement-cache.cxx
    odb/sqlite/stream.cxx
    odb/sqlite/tracer.cxx
    odb/sqlite/traits.cxx
    odb/sqlite/transaction.cxx
    odb/sqlite/transaction-impl.cxx

    odb/sqlite/details/options.cxx
)

IF (UNIX)
    set(ODBSQLITE_INCLUDE
        ${ODBSQLITE_INCLUDE}
        odb/sqlite/details/config.h
    )
ENDIF()

add_definitions(
    -DLIBODB_SQLITE_HAVE_UNLOCK_NOTIFY
    -DLIBODB_SQLITE_HAVE_COLUMN_METADATA
)

add_library(odb-sqlite ${ODBSQLITE_INCLUDE} ${ODBSQLITE_SRC})
target_link_libraries(odb-sqlite sqlite3 odb)
target_include_directories(odb-sqlite PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
if(BUILD_SHARED_LIBS)
    target_compile_definitions(odb-sqlite
        PUBLIC LIBODB_SQLITE_DYNAMIC_LIB DATABASE_SQLITE)
else()
    target_compile_definitions(odb-sqlite
        PUBLIC LIBODB_SQLITE_STATIC_LIB DATABASE_SQLITE)
endif()

set(ODBSQLITE_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
SET_TARGET_PROPERTIES(odb-sqlite
    PROPERTIES
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    DEBUG_OUTPUT_NAME odb-sqlite-d
    RELEASE_OUTPUT_NAME odb-sqlite
)
