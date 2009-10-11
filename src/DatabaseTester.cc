#include "DatabaseTester.hh"

void
DatabaseTester::connect (const QString &server, const QString &db, const QString &uid, const QString &pwd) {
	emit connecting ();

	if (m_login || m_dbproc) {
		//FIXME - already connected
		emit connected ();
		return;
	}

	if ((m_login = syb::dblogin ()) == 0) {
		//FIXME - no memory
		emit error ("Out of memory");
		return;
	}

	syb::DBSETLUSER(m_login, uid.toAscii ().data ());
	syb::DBSETLPWD(m_login, pwd.toAscii ().data ());

	if ((m_dbproc = syb::dbopen (m_login, server.toAscii ().data ())) == 0) {
		//FIXME - unable to open database server
		emit error ("Unable to open database server");
		return;
	}

	if ((m_ret = syb::dbuse (m_dbproc, db.toAscii ().data ())) == FAIL) {
		//FIXME - database name doesn't exist on server
		emit error ("Database name does not exist");
		return;
	}

	emit connected ();
}

void
DatabaseTester::disconnect () {
	if (m_dbproc) {
		syb::dbclose (m_dbproc);
		m_dbproc = 0;
	}

	if (m_login) {
		syb::dbloginfree (m_login);
		m_login = 0;
	}
}

void
DatabaseTester::spChecksumsInsert (const QString &userid, const QString &testid, int regcksum, int ramcksum) {
	syb::dbfcmd (m_dbproc, "exec ChecksumsInsert \"%s\", \"%s\", %d, %d", userid.toAscii ().data (), testid.toAscii ().data (), regcksum, ramcksum);
	m_ret = syb::dbsqlexec (m_dbproc);
}
