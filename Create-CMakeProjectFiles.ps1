foreach($d in Get-ChildItem -Directory -Recurse)
{
  $name = $d.Name
  $path = $d.FullName
  
  if ((Test-Path "$path/*.vcxproj") ) #-and (-not (Test-Path "$path\CMakeLists.txt")))
  {
    Write-Host -ForegroundColor Yellow "Creating CMakeLists.txt for prject '$name'..."
    $content = "cmake_minimum_required(VERSION 3.27)`n"
    $content += "project($name)`n`n"
    $content += "set(CMAKE_CXX_STANDARD 20)`n`n"
    $content += "add_executable($name main.cpp"
    foreach($h in Get-ChildItem -Path $path -Filter *.h)
    {
      $content += "`n        $($h.Name)"
    }
    $content += ")`n"

    Set-Content -Path "$path\CMakeLists.txt" -Value $content
    Write-Host "$path\CMakeLists.txt`n"
  }
}