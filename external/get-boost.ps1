
$BOOST_VER_DS = $args[0]
$BOOST_VER_US = $BOOST_VER_DS.replace('.', '_')
$BOOST_DIR = "boost_$BOOST_VER_US"
$BOOST_ZIP = "boost_$BOOST_VER_US.zip"
$BOOST_URL = "http://downloads.sourceforge.net/project/boost/boost/$BOOST_VER_DS/$BOOST_ZIP"

if (!(Test-Path "$BOOST_ZIP")) {
    $webClient = new-object System.Net.WebClient
    $webClient.DownloadFile("$BOOST_URL", "$BOOST_ZIP")
}

if (!(Test-Path "$BOOST_DIR")) {

    [System.Reflection.Assembly]::LoadWithPartialName('System.IO.Compression.FileSystem') | Out-Null
    [System.IO.Compression.ZipFile]::ExtractToDirectory("$BOOST_ZIP", ".")
}
