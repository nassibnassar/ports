PORTNAME=	amberfish
PORTVERSION=	1.7.1
CATEGORIES=	textproc databases

MAINTAINER=	nrn@etymon.com
COMMENT=	Full-text search engine with command-line interface
WWW=		https://gitlab.com/amberfish/amberfish

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxerces-c.so:textproc/xerces-c3

USES=		gmake

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

ALL_TARGET=	all html

PLIST_FILES=	bin/af
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
DOCS_PLIST_FILES=	share/man/man1/af.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${MAKEFLAGS} ||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|cp |$${BSD_INSTALL_MAN} |' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-O3 |@CFLAGS@ | ; \
		s|make strip|| ; \
		s|cp |$${BSD_INSTALL_PROGRAM} |' ${WRKSRC}/src/backend/Makefile.in

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e \
		'/cd doc/d' ${WRKSRC}/Makefile

post-configure:
	echo "#define AF_VERSION \"v${PORTVERSION}\"" > ${WRKSRC}/src/backend/version.h
	echo v${PORTVERSION} > ${WRKSRC}/doc/version.adoc

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/amberfish.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
