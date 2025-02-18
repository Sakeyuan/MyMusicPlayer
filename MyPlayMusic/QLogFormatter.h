#ifndef QLOGFORMATTER_H
#define QLOGFORMATTER_H
#include <spdlog/fmt/ostr.h>
#include <QString>

namespace fmt {
    template <>
    struct formatter<QString> {
        template <typename ParseContext>
        constexpr auto parse(ParseContext& ctx) { return ctx.begin(); }

        template <typename FormatContext>
        auto format(const QString& str, FormatContext& ctx) {
            return format_to(ctx.out(), "{}", str.toStdString());
        }
    };
}

#endif // QLOGFORMATTER_H
