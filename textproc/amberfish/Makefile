PORTNAME=	amberfish
DISTVERSION=	1.7.1
CATEGORIES=	textproc databases

USE_GITLAB=	yes
GL_COMMIT=	d0b6e49d750e2c445a4c6526422d4ff43bc668d7

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

post-configure:
	echo "#define AF_VERSION \"v${PORTVERSION}\"" > ${WRKSRC}/src/backend/version.h
	echo v${PORTVERSION} > ${WRKSRC}/doc/version.adoc

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/amberfish.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
