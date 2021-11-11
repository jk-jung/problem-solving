def validate(email)
  (/^[\w-]+(\.[\w-]+)*@[\w-]+(\.[\w-]+)+$/ =~ email) != nil
end
